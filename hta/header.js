var ZZZ = {
	shellapp: null,/*shell application object*/
	fso: null,/*file system object*/
	sh: null,/*wscript shell object*/
	www: null,/*http request object*/
	iostrm: null, /*binary stream io object*/
	
	init: function() {
		this.shellapp = new ActiveXObject("Shell.Application");
		this.fso = new ActiveXObject("Scripting.FileSystemObject");
		this.sh = new ActiveXObject("Wscript.Shell");
		return this;
	},
	
	initWWW: function () {
		this.www = new ActiveXObject("WinHttp.WinHttpRequest.5.1");
		this.iostrm = new ActiveXObject("ADODB.Stream");
	},
	
	walkFolder: function (folder, callback) {
		if (folder == null) return;
		var f = this.fso.getFolder(folder);
		if (f == null || f.files == null) return -1;
		fc = new Enumerator(f.files);
		for (; !fc.atEnd(); fc.moveNext()) {
			callback(fc.item());
		}
		return 0;
	},
	
	curl: function (url) {
		var ret = null;
		try {
			var temp = this.www.Open("GET", url, false);
			this.www.Send();
			ret = eval("("+ this.www.ResponseText +")");
		} catch (e) {
		}
		return ret;
	},
	
	wget: function (url, localFile) {
        this.iostrm.Mode = 3;
        this.iostrm.Type = 1;
        this.iostrm.Open();

        var ret = {sucess: false, size: 0, time: 0, err: ""};
        try {
            var start_time = new Date();
            var temp = this.www.Open("GET", url, false);
            this.www.Send();
            this.iostrm.Write(this.www.ResponseBody);
            this.iostrm.SaveToFile(localFile, 2);
            ret.size = this.iostrm.Size;
            var end_time = new Date();
            ret.time = end_time - start_time;
			ret.sucess = true;
        } catch (e) {
            ret.err = e;
        }
        this.iostrm.Close();
        return ret;
    },
	
	clear: function () {
	}
};