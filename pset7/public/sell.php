<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $rows =	CS50::query("SELECT * FROM Portfolio WHERE user_id = ?", $_SESSION["id"]);	
        
        // create new array to store stock symbols
        $symbols = [];
        foreach ($rows as $row)	
        {   
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $symbols[] = [
                    "name" => $stock["name"],
                    "symbol" => $row["symbol"],
                ];
            } 
        }    
        
        // else render form
        render("sell_form.php", ["title" => "Sell", "symbols" => $symbols]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["shares"] == NULL)
        {
            apologize("Please fill out how many shares");
        }
        
        if (preg_match("/^\d+$/", $_POST["shares"]) != true)
        {
            apologize("Only non-fractional shares please");
        }    
        
        if ($_POST["shares"] == 0)
        {
            apologize("Please enter a valid share number");
        }
        
        $stock = lookup($_POST["symbol"]);
        if ($stock == NULL)
        {
            apologize("This stock doesn't exist.");
        }
        $trans = 'SELL';
        $shares = CS50::query("SELECT shares FROM Portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        $money = $stock["price"] * $_POST["shares"];
        
        if ($_POST["shares"] > $shares[0]["shares"])
        {
            apologize("You don't have enough shares");
        }
        if ($_POST["shares"] != $shares[0]["shares"])
        {
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $money, $_SESSION["id"]);
        
        CS50::query("UPDATE Portfolio SET shares = shares - ? WHERE user_id = ? AND symbol = ?", $_POST["shares"], $_SESSION["id"], $_POST["symbol"]);
        
        CS50::query("INSERT INTO history (user_id, trans, symbol, shares, price, datetime) VALUES(?, ?, ?, ?, ?, NOW())", $_SESSION["id"], $trans, strtoupper($_POST["symbol"]), $_POST["shares"], $stock["price"]);
        redirect("/");
        }
        else
        {
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $money, $_SESSION["id"]);
        
        CS50::query("DELETE FROM Portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        CS50::query("INSERT INTO history (user_id, trans, symbol, shares, price, datetime) VALUES(?, ?, ?, ?, ?, NOW())", $_SESSION["id"], $trans, strtoupper($_POST["symbol"]), $_POST["shares"], $stock["price"]);
        redirect("/");
        }
    }
?>