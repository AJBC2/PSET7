<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("change_form.php", ["title" => "Change Password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["newpass"] == NULL ||  $_POST["confirmation"] == NULL )
        {
            apologize("Fill in all the information please");
        }
        
        if ($_POST["newpass"] !== $_POST["confirmation"])
        {
            apologize("Make sure your new password is the same as the confirmation
            please");
        }
        
        CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["newpass"], PASSWORD_DEFAULT), $_SESSION["id"]);
        redirect("/");
    }
?>