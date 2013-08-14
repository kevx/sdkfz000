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
    $$(function () {
        $$("#J_loginBtn").on("click", function (ev) {
            $$("#J_loginForm").submit();
        });
    })
</script>

<div>
	<div class="intro comm-block">
	</div>
	
	<div class="index">
		<div class="operation">
			<ul>
				<form id="J_loginForm" action="" method="post">
				<input type="hidden" name="action" value="login"/>
                <input type="hidden" name="redirect" value="$o['redirectTo']"/>
                
				$if core.session().has_key('logined') and core.session()['logined'] == True:
					<li>登陆成功</li>
				$else:
					<li>账号：<input type="text" class="basic-input" name="email" style="width:120px;"/></li>
					<li>密码：<input type="password" class="basic-input" name="passwd" style="width:120px;"/></li>
					<li>
						<span class="usr-btn" style="float: left">
							<a href="javascript:void(0)" id="J_loginBtn">登入</a>
						</span>
					</li>
				</form>
			</ul>
		</div>

	</div>
</div>

