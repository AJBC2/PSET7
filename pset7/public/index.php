<?php

    // configuration
    require("../includes/config.php"); 

    $id = $_SESSION["id"];
    $rows = CS50::query("SELECT symbol, shares FROM Portfolio WHERE user_id = $id");
    
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => ($row["shares"] * $stock["price"]),
            ];
        }
    }
    
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);

?>
