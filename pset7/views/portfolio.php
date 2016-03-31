<table class="table table-striped">

<thead>
    <tr>
        <th>Symbol</th>
        <th>Shares</th>
        <th>Price</th>
        <th>Name</th>
        <th>TOTAL</th>
    </tr>
</thead>
    
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
    Do you want to change your password? Click <a href="prechange.php">here</a>.
</div>
<div>
    <?php
    $balance = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    ?>
    <h3>Your balance is: $<?= $balance[0]["cash"] ?></h3>
</div>

</table>