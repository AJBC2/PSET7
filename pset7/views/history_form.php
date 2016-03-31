<table class="table table-striped">

<thead>
    <tr>
        <th>Transaction</th>
        <th>Date/Time</th>
        <th>Symbol</th>
        <th>Shares</th>
        <th>Price</th>
    </tr>
</thead>
    
<tbody>
    <?php

        foreach ($positions as $position)
        {
            print("<tr>");
            print("<th><h4>{$position["trans"]}<h4></th>");
            print("<th><h4>{$position["datetime"]}<h4></th>");
            print("<th><h4>{$position["symbol"]}<h4></th>");
            print("<th><h4>{$position["shares"]}<h4></th>");
            print("<th><h4>{$position["price"]}<h4></th>");
            print("</tr>");
        }

    ?>
</tbody>

</table>