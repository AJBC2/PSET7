<?php
    // configuration
    require("../includes/config.php");
    
    $id = $_SESSION["id"];
    $rows = CS50::query("SELECT symbol, shares, trans, datetime FROM history WHERE user_id = $id");
    
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "trans" => $row["trans"],
                "datetime" => $row["datetime"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "price" => $stock["price"],
            ];
        }
    }
    
    // render history
    render("history_form.php", ["title" => "History", "positions" => $positions]);
?>