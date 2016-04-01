<table class="table table-striped">

<thead>
    <tr>
        <th style= "color: cornflowerblue; font-family: Bell MT"><h2>Symbol</h2></th>
        <th style= "color: cornflowerblue; font-family: Bell MT"><h2>Shares</h2></th>
        <th style= "color: cornflowerblue; font-family: Bell MT"><h2>Price</h2></th>
        <th style= "color: cornflowerblue; font-family: Bell MT"><h2>Name</h2></th>
        <th style= "color: cornflowerblue; font-family: Bell MT"><h2>TOTAL</h2></th>
    </tr>
</thead>

    <body style="background-color: #F8F8FF">
        
<tbody>
    <?php

        foreach ($positions as $position)
        {
            print("<tr>");
            print("<th><h4>{$position["symbol"]}<h4></th>");
            print("<th><h4>{$position["shares"]}<h4></th>");
            print("<th><h4>{$position["price"]}<h4></th>");
            print("<th><h4>{$position["name"]}<h4></th>");
            print("<th><h4>{$position["total"]}<h4></th>");
            print("</tr>");
        }

    ?>
</tbody>

<div>
    <?php
    $balance = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    ?>
    <h4 style = "color: dark blue; font-family: Bookman Old Style">Your balance is: $<?= $balance[0]["cash"] ?></h4>
</div>

</table>