$def with(core, o)

<link rel="stylesheet" type="text/css" href="/static/pm-brief.css">
<script>
    $$(function(){
        $$("#tabs").tabs();
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
        <li><a href="/pm/brief"  class="curr-link ui-state-focus">基本资料</a></li>
        <li><a href="/pm/skills">职业技能</a></li>
        <li><a href="/pm/career">程序生涯</a></li>
        <li><a href="#">找伯乐</a></li>
    </ul>
</div>

<div id="tabs">
    <ul class="nav nav-tabs">
        <li><a href="#tab-1">联系资料</a></li>
        <li><a href="#tab-2">技术博客</a></li>
        <li><a href="#tab-3">开源事业</a></li>
    </ul>
    
    <div id="tab-1">
        <table>
            <tr>
                <td>邮箱</td>
                <td><input type="text" name="email" class="basic-input"/></td>
            </tr>
            
            <tr>
                <td>手机号</td>
                <td><input type="text" name="iphone" class="basic-input"/></td>
            </tr>
            
            <tr>
                <td>微博</td>
                <td><input type="text" name="weibo" class="basic-input"/></td>
            </tr>
            
            <tr>
                <td>QQ</td>
                <td><input type="text" name="qq" class="basic-input"/></td>
            </tr>
            
            <tr>
                <td><input type="submit" value="保存" class="enabled btn-submit"/></td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </div>
    
    <div id="tab-2">
        <table>
            <tr>
                <td>主力博客</td>
                <td><input type="text" name="mainBlog" class="basic-input"/></td>
            </tr>
            
            <tr>
                <td>次要博客</td>
                <td><input type="text" name="subBlog" class="basic-input"/></td>
            </tr>
        </table>
    </div>
    
    <div id="tab-3">
        <table>
            <tr>
                <td>GitHub</td>
                <td><input type="text" name="github" class="basic-input"/></td>
            </tr>
            
            <tr>
                <td>GoogleCode</td>
                <td><input type="text" name="googleCode" class="basic-input"/></td>
            </tr>

        </table>
    </div>
</div>

<br/>

