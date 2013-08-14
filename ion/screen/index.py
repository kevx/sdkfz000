$def with(core, o)

<style>
	.intro {
		font-size: medium;
	}
	
	.operation {
		float: left;
	}
	
	.index-dyn {
		border-left-style: solid;
		border-left-color: #dddddd;
		margin-left: 45px;
		width: 600px;
		padding: 15px;
		min-height: 250px;
		float: left;
	}
	
	ul {
		padding: 0;
	}
	
	li {
		list-style: none;
		margin-left: 0;
		margin-bottom: 5px;
	}
	
	td {
		width: 150px;
		height: 100px;
		vertical-align: top;
	}
</style>
<script>
    
</script>

<div>
	<div class="hero-unit">
		<h1>Hello, world!</h1>
		<p>
            This is a template for a simple marketing or informational website. 
            It includes a large callout called the hero unit and three supporting pieces of content. 
            Use it as a starting point to create something more unique.
        </p>
        <p>
            <a href="#" class="btn btn-primary btn-large">Learn more »</a>
        </p>
	</div>
	
	<div class="index">
		<div class="operation">
			<ul>
				<form id="J_loginForm" action="/index" method="post">
				<input type="hidden" name="action" value="login"/>
				$if core.session().has_key('authed') and core.session()['authed'] == True:
					<li>登陆成功</li>
				$else:
					<li>账号：<input type="text" class="basic-input" style="width:120px;"/></li>
					<li>密码：<input type="password" class="basic-input" style="width:120px;"/></li>
					<li>
                        <a class="btn btn-primary" href="/pm/register/form">注册账号</a>
					</li>
				</form>
			</ul>
		</div>
		
		<div class="index-dyn">
			<span class="title">这些人刚刚加入了...</span>
			<div style="margin-bottom: 15px;"></div>
			<table>
			$for i in range(2):
				<tr>
				$for ii in range(4):
					<td>
						<img src="http://tp4.sinaimg.cn/1738094551/50/5596816474/1" />&nbsp;哈哈
					</td>
				</tr>
			</table>
		</div>
	</div>
</div>

