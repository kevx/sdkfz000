var ifs = document.getElementsByTagName("iframe");
for (var i = 0; i < ifs.length; i++) {
    var src = ifs[i].src;
    if (src.indexOf('alimama') >= 0 || src.indexOf('www.56.com/js/promo') >= 0) {
        alert(src);
        ifs[i].parentNode.removeChild(ifs[i]);
    }
}