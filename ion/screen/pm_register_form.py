$def with(core, o)
<script>
    $$(function(){
    });
</script>

<table>
    <thead>
        <tr><td></td><td></td></tr>
        <tr><td></td><td></td></tr>
    </thead>
    
    <tbody>
        <tr>
            <td>昵称</td>
            <td><input type="text" name="nick" class="basic-input"/></td>
        </tr>
        <tr>
        </tr>
        
        <tr>
            <td>真实姓名</td>
            <td><input type="text" name="realName" class="basic-input"/></td>
        </tr>
        
        <tr>
            <td>工作年限</td>
            <td>
                <select name="workYears" class="basic-input">
                    <option value="0">0~1年</option>
                    <option value="1">1~3年</option>
                    <option value="2">3年以上</option>
                    <option value="3">5年以上</option>
                </select> 
            </td>
        </tr>
        
        <tr>
            <td>当前年薪</td>
            <td>
                <select name="companyLevel" class="basic-input">
                    <option value="0">10w以下</option>
                    <option value="1">10w~20w</option>
                    <option value="2">20w~50w</option>
                    <option value="3">50w以上</option>
                </select> 
            </td>
        </tr>
        
        <tr>
            <td>公司名称</td>
            <td>
                <input type="text" name="companyName" class="basic-input"/>
            </td>
        </tr>
        
        <tr>
            <td><input type="submit" value="提交" class="enabled btn-submit"/></td>
            <td></td>
        </tr>
    </tbody>
</table>