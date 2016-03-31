<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["username"] == NULL || $_POST["password"] == NULL)
        {
            apologize("Fill in a username and password please");
        }
        if ($_POST["name"] == NULL || $_POST["surname"] == NULL)
        {
            apologize("Fill in your name and surname please");
        }
        
        if ($_POST["password"] !== $_POST["confirmation"])
        {
            apologize("Make sure your password is the same as the confirmation
            please");
        }
        
            $inp = CS50::query("INSERT IGNORE INTO users (username, hash, cash, name, surname) 
            VALUES(?, ?, 10000.0000, ?, ?)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT), $_POST["name"], $_POST["surname"]);
        
            if ($inp === 0)
            {
                apologize("Registration failed");
            }
            else
            {
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                if (count($rows) == 1)
                    {
                        $id = $rows[0]["id"];
                        $_SESSION["id"] = $id;
                        redirect("/");
                    }
            }
    }
?>