$def with(core, o)

<style>
    .d-left-nav .search {
        border-left-style: solid;
        border-left-color: #0073ea;
        border-left-width: 20px;
        padding-left: 10px;
        font-size: 16px;
    }

    .main-list {
        border-left-style: solid;
        border-left-color: #dddddd;
        margin-left: 45px;
        float: left;
        width: 600px;
        padding: 15px;
        min-height: 500px;
    }
</style>

<script>
    $$(function () {
        
    });
</script>

<div class="d-left-nav">
    <span class="title">搜索</span>
    <div>
		<ul>
			<li>工作经验:
				<select class="basic-input">
					<option value="-1">不限制</option>
					<option value="1">0~3年</option>
					<option value="2">3~5年</option>
					<option value="3">5年以上</option>
				</select>
			</li>
			
			<li>当前状态:
				<select class="basic-input">
					<option value="-1">不限制</option>
					<option value="0">无意向</option>
					<option value="1">想跳</option>
				</select>
			</li>

		</ul>
		<input type="submit" value="搜！" class="enabled btn-submit"/>
	</div>
</div>

<div class="main-list">
	<div class="comm-block">
		<div class="action">
			<span class="usr-btn">
				<a href="#">联系</a>
				<a href="/pm/detail">详情</a>
			</span>
		</div>
		
		<div class="title">赫鲁晓夫</div>
		
		<div class="content">
			<div style="margin-top:10px;">
			<span class="pm-tag">C++程序员</span>
			<span class="pm-tag">非常NB</span>
			</div>
			
			<table>
				<tr>
					<td class="comm-txt">当前所在：</td>
					<td class="comm-txt">哈哈哈哈公司</td>
					
					<td class="comm-txt">地区：</td>
					<td class="comm-txt">阿斯大苏打撒</td>
				</tr>
				
				<tr>
					<td class="comm-txt">个人简介:</td>
					<td class="comm-txt">哈哈哈哈哈哈哈哈哈哈哈哈</td>
				</tr>
			</table>
		</div>
	</div>
	
	<div class="comm-block">
		<div class="action">
			<span class="usr-btn">
				<a href="/pm/detail">详情</a>
				<a href="/pm/detail">联系</a>
			</span>
		</div>
		
		<div class="title">猫贼咚</div>
		<div class="content">
			<div style="margin-top:10px;">
				<span class="pm-tag">C++程序员</span>
				<span class="pm-tag">非常NB</span>
			</div>
			<table>
				<tr>
					<td class="comm-txt">当前所在：</td>
					<td class="comm-txt">哈哈哈哈公司</td>
					
					<td class="comm-txt">地区：</td>
					<td class="comm-txt">HELL</td>
				</tr>
				
				<tr>
					<td style="vertical-align:top;" class="comm-txt">个人简介：</td>
					<td><span class="desc">哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈</span></td>
				</tr>
			</table>
		</div>
	</div>
</div>