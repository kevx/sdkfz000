$def with(core, o)

<script>
    $$(function(){
        $$("#left-nav-god").menu();
    });
</script>


<div class="d-left-nav">
    <span></span><br/>
    <ul id="left-nav-god">
        <li><a href="#">基本资料</a></li>
        <li><a href="#">展示中心</a></li>
        <li><a href="#">我要跳</a></li>
    </ul>
</div>
$if o:
    <h3>$o["name"]</h3>
$else:
    <h2>Nothing</h2>
