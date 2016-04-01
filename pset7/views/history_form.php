<table class="table table-striped">
<body style="background-color: #F5F5F5">
<thead>
    <tr>
        <th style= "color: salmon; font-family: Bell MT"><h2>Transaction</h2></th>
        <th style= "color: salmon; font-family: Bell MT"><h2>Date/Time</h2></th>
        <th style= "color: salmon; font-family: Bell MT"><h2>Symbol</h2></th>
        <th style= "color: salmon; font-family: Bell MT"><h2>Shares</h2></th>
        <th style= "color: salmon; font-family: Bell MT"><h2>Price</h2></th>
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

<img src= "http://www.childrenandyouth.co.uk/wp-content/uploads/2015/03/Make-Good-Choices.png" style = "width: 700x; height: 200px"/>