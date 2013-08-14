$def with(core, content)
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
    <head>
        $core.widget('head')
        
        <script>
        $$(function () {
            $$("#J_loginBtn").on("click", function (ev) {
                $$("#J_loginForm").submit();
            });
        })
        </script>
    </head>
    <body>
    
    <div class="navbar navbar-fixed-top">
        <div class="navbar-inner" style="height: 50px;">
            <div class="container">
                <button type="button" class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="brand" href="#">Project name</a>
                <div class="nav-collapse collapse">
                    <ul class="nav">
                        <li class="active"><a href="#">首页</a></li>
                        <li><a href="#about">程序员</a></li>
                        <li><a href="#contact">HR</a></li>
                        <li class="dropdown">
                            <a href="#" class="dropdown-toggle" data-toggle="dropdown">Dropdown <b class="caret"></b></a>
                            <ul class="dropdown-menu">
                                <li><a href="#">Action</a></li>
                                <li><a href="#">Another action</a></li>
                                <li><a href="#">Something else here</a></li>
                                <li class="divider"></li>
                                <li class="nav-header">Nav header</li>
                                <li><a href="#">Separated link</a></li>
                                <li><a href="#">One more separated link</a></li>
                            </ul>
                        </li>
                    </ul>
                    <form class="navbar-form pull-right" id="J_loginForm">
                        <input type="hidden" name="action" value="login"/>
                    $if core.session().has_key('authed') and core.session()['authed'] == True:
                        <li>Hello!</li>
                    $else:
                        <input class="span2" type="text" placeholder="Email">
                        <input class="span2" type="password" placeholder="Password">
                        <button type="submit" class="btn" id="J_loginBtn">登入</button>
                    </form>
                </div><!--/.nav-collapse -->
            </div>
        </div>
    </div>
    
    <div class="container">
    $:content
    </div>
    
    
    <div class="footer">
        $core.widget('footer')
    </div>
    
    </body>
</html>