defer = "true";

function hide(id){
	document.getElementById(id).style.transitionProperty="opacity .5s linear";
		document.getElementById(id).style.opacity=0;
		document.getElementById(id).style.pointerEvents="none";
		document.getElementById(id).style.cursor="default";
		
		
}
function show(id){
		document.getElementById(id).style.transition="opacity .5s linear";
		document.getElementById(id).style.opacity=1;
		document.getElementById(id).style.pointerEvents="auto";
		document.getElementById(id).style.cursor="hand";
}
function newShareWindow(url,w,h) {
  var left = (screen.width/2)-(w/2);
  var top = (screen.height/2)-(h/2);
newwindow=window.open(url,'share-window', 'width='+w+', height='+h+', top='+top+', left='+left);
	if (window.focus) {
		newwindow.focus()
	}
	return false;
}


var count = (function() {
	var counter = 0;
	return function() {
		return counter += 1;
	}
})();

function isDate(myDate) {
	return myDate.constructor.toString().indexOf("Date") > -1;
}

function isArray(myArray) {
	return myArray.constructor.toString().indexOf("Array") > -1;
}

function startTime() {
	var today = new Date();
	var h = today.getHours();
	var m = today.getMinutes();
	var s = today.getSeconds();
	var day = today.getDate();
	var mon = today.getMonth();
	var year = today.getFullYear();
	var ampm = h >= 12 ? 'PM' : 'AM';
	h = h % 12;
	h = h ? h : 12;
	m = checkTime(m);
	s = checkTime(s);
	day = checkTime(day);
	mon = checkTime(mon);
	document.getElementById('clockTime').innerHTML = h + ":" + m + ":" + s + " " + ampm;
	document.getElementById('clockDate').innerHTML = day + "/" + mon + "/" + year;
	var store=fillStorage();
	var t = setTimeout(function() {
		startTime()
	}, 500);
}

function checkTime(i) {
	if (i < 10) {
		i = "0" + i
	};// add zero in front of numbers < 10
	return i;
}



//below taken from http://www.howtocreate.co.uk/tutorials/javascript/browserwindow
function getScrollXY() {
    var scrOfX = 0, scrOfY = 0;
    if( typeof( window.pageYOffset ) == 'number' ) {
        //Netscape compliant
        scrOfY = window.pageYOffset;
        scrOfX = window.pageXOffset;
    } else if( document.body && ( document.body.scrollLeft || document.body.scrollTop ) ) {
        //DOM compliant
        scrOfY = document.body.scrollTop;
        scrOfX = document.body.scrollLeft;
    } else if( document.documentElement && ( document.documentElement.scrollLeft || document.documentElement.scrollTop ) ) {
        //IE6 standards compliant mode
        scrOfY = document.documentElement.scrollTop;
        scrOfX = document.documentElement.scrollLeft;
    }
    return [ scrOfX, scrOfY ];
}

//taken from http://james.padolsey.com/javascript/get-document-height-cross-browser/
function getDocHeight() {
    var D = document;
    return Math.max(
        D.body.scrollHeight, D.documentElement.scrollHeight,
        D.body.offsetHeight, D.documentElement.offsetHeight,
        D.body.clientHeight, D.documentElement.clientHeight
    );
}

document.addEventListener("scroll", function (event) {
	    if (getDocHeight() <= (getScrollXY()[1] + window.innerHeight+100)) {
        hide('share-button-fixed');
    }
    else{show('share-button-fixed');}
	
	if(getScrollXY()[1]>=190){document.getElementById('content-links').style.top="1em";}
	else {document.getElementById('content-links').style.top=240-getScrollXY()[1]+"px";}
	

});
