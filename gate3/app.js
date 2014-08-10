var httpProxy = require('http-proxy');
var https = require('https')
    ,fs = require("fs");


var proxy = httpProxy.createProxyServer({});
proxy.on('proxyReq', function(proxyReq, req, res, options) {
  proxyReq.setHeader('X-Special-Proxy-Header', 'foobar');
});


var options = {
    key: fs.readFileSync('./privatekey.pem'),
    cert: fs.readFileSync('./certificate.pem')
};

https.createServer(options, function (req, res) {
    proxy.web(req, res, {
    target: 'http://www.google.com'
  });
}).listen(7443);
