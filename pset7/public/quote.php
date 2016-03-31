<?php
    // configuration
    require("../includes/config.php"); 
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // Validate the name
        if (empty($_POST["code"]))
        {
            apologize("Please enter the stock symbol.");
        }
        
        $stock = lookup($_POST["code"]);
        
        // Check if we returned nothing
        if ($stock === false)
        {
            apologize("Entered stock symbol was invalid.");
        }
        else
        {
            // Render the result form
            render("quote_views.php", ["title" => "Quote", "stock" => $stock]);
        }
    }
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
?>