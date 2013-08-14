$def with(core, o)

<link rel="stylesheet" type="text/css" href="/static/pm-career.css">
<script>
    $$(function(){
        $$("#left-nav-god").menu();
    });
</script>

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
        <li><a href="/pm/skills">职业技能</a></li>
        <li><a href="/pm/career"   class="curr-link ui-state-focus">程序生涯</a></li>
        <li><a href="#">找伯乐</a></li>
    </ul>
</div>


<div class="career-content">
	<div class="career-block">
		<span class="year">2001</span>
		<span class="project-desc">
			<textArea class="desc-edit">项目项目项目项目项目项目项目</textArea>
		</span>
	</div>
	
	<div class="career-block">
		<span class="year">2010</span>
		<span class="project-desc">
			项目项目项目项目项目项目项目
			<textArea class="desc-edit">项目项目项目项目项目项目项目</textArea>
		</span>
	</div>
</div>
