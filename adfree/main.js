chrome.browserAction.onClicked.addListener(function(tab) {
    var url = tab.url;
    alert('###url is:' + url);
    chrome.tabs.executeScript(null, {
        file: 'func.js'
    });
})