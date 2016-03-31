<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("prechange_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["oldpass"] == NULL)
        {
            apologize("You must provide your current password first, please.");
            redirect("prechange.php");
        }
        
        // query database for user
        $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);

        // if we found user, check password
        if (count($rows) == 1)
        {
            // first (and only) row
            $row = $rows[0];

            // compare hash of user's input against hash that's in database
            if (password_verify($_POST["oldpass"], $row["hash"]))
            {
                // redirect to portfolio
                redirect("change.php");
            }
        }

        // else apologize
        apologize("Invalid password.");
    }
?>