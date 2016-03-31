<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["shares"] == NULL || $_POST["symbol"] == NULL)
        {
            apologize("Please fill out all the information");
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
        $trans = 'BUY';
        
        if ($stock === false)
        {
            apologize("Stock does not exist");
        }
        
        $money2 = $stock["price"] * $_POST["shares"];
        
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
        if ($money2 > $cash[0]["cash"])
        {
            apologize("You don't have the money");
        }
        else
        {
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $money2, $_SESSION["id"]);
            CS50::query("INSERT INTO Portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"]);
            CS50::query("INSERT INTO history (user_id, trans, symbol, shares, price, datetime) VALUES(?, ?, ?, ?, ?, NOW())", $_SESSION["id"], $trans, strtoupper($_POST["symbol"]), $_POST["shares"], $stock["price"]);
            redirect("/");
        } 
    }
?>