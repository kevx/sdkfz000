$def with(core, o)

<link rel="stylesheet" type="text/css" href="/static/pm-skills.css"/>
<script>
    $$(function(){
        $$("#left-nav-god").menu({
			focus: function( event, ui ) {
				$$(".curr-link").removeClass("ui-state-focus");
			},
			
			blur: function( event, ui ) {
				$$(".curr-link").addClass("ui-state-focus");
			} 
		});
    });
</script>

<div class="d-left-nav">
    <ul id="left-nav-god">
        <li><a href="/pm/brief">基本资料</a></li>
        <li><a href="/pm/skills" class="curr-link ui-state-focus">职业技能</a></li>
        <li><a href="/pm/career">程序生涯</a></li>
        <li><a href="#">找伯乐</a></li>
    </ul>
</div>

<div>
    <ul>
    
    </ul>
</div>