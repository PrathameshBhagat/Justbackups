const char SUPPORT_page[] PROGMEM = R"=====(
<br><br><br>
<input type="range" min="0" max="180" value="50" step="10"
oninput=" var xhttp = new XMLHttpRequest();xhttp.open('GET', 'distance?pwm='+this.value,true );xhttp.send();"><br><br><br>
<input type="range" min="0" max="255" value="50" step="10" style='accent-color:#ff9900;'
oninput=" var xhttp = new XMLHttpRequest();xhttp.open('GET', 'distance?analog='+this.value,true );xhttp.send();">
)=====";   
  const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
*{ margin:0px; padding: 0px;color:#cc00ff; user-select: none;	font-family: monospace;}
.row{display: inline-flex;	}
.a{ width :55px;}
#joy1Div,#joy2Div {
	--m:max(100vh,100vw);
	width:calc(var(--m)/2.3);
	height:calc(var(--m)/2.3); 
	}
#joy1Div>#joystick{
    border:1px solid #ff0000; 
}
#joy2Div>#joystick{
    border:1px solid #0000ff;
}
    </style><script >let StickStatus={xPosition:0,yPosition:0,x:0,y:0,cardinalDirection:"C"};var JoyStick=function(t,e,i){var o=void 0===(e=e||{}).title?"joystick":e.title,n=void 0===e.width?0:e.width,a=void 0===e.height?0:e.height,r=void 0===e.internalFillColor?"#00AA00":e.internalFillColor,c=void 0===e.internalLineWidth?2:e.internalLineWidth,s=void 0===e.internalStrokeColor?"#003300":e.internalStrokeColor,d=void 0===e.externalLineWidth?2:e.externalLineWidth,u=void 0===e.externalStrokeColor?"#008000":e.externalStrokeColor,h=void 0===e.autoReturnToCenter||e.autoReturnToCenter;i=i||function(t){};var S=document.getElementById(t);S.style.touchAction="none";var f=document.createElement("canvas");f.id=o,0===n&&(n=S.clientWidth),0===a&&(a=S.clientHeight),f.width=n,f.height=a,S.appendChild(f);var l=f.getContext("2d"),k=0,g=2*Math.PI,x=(f.width-(f.width/2+10))/2,v=x+5,P=x+30,m=f.width/2,C=f.height/2,p=f.width/10,y=-1*p,w=f.height/10,L=-1*w,F=m,E=C;function W(){l.beginPath(),l.arc(m,C,P,0,g,!1),l.lineWidth=d,l.strokeStyle=u,l.stroke()}function T(){l.beginPath(),F<x&&(F=v),F+x>f.width&&(F=f.width-v),E<x&&(E=v),E+x>f.height&&(E=f.height-v),l.arc(F,E,x,0,g,!1);var t=l.createRadialGradient(m,C,5,m,C,200);t.addColorStop(0,r),t.addColorStop(1,s),l.fillStyle=t,l.fill(),l.lineWidth=c,l.strokeStyle=s,l.stroke()}function D(){let t="",e=F-m,i=E-C;return i>=L&&i<=w&&(t="C"),i<L&&(t="N"),i>w&&(t="S"),e<y&&("C"===t?t="W":t+="W"),e>p&&("C"===t?t="E":t+="E"),t}"ontouchstart"in document.documentElement?(f.addEventListener("touchstart",function(t){k=1},!1),document.addEventListener("touchmove",function(t){1===k&&t.targetTouches[0].target===f&&(F=t.targetTouches[0].pageX,E=t.targetTouches[0].pageY,"BODY"===f.offsetParent.tagName.toUpperCase()?(F-=f.offsetLeft,E-=f.offsetTop):(F-=f.offsetParent.offsetLeft,E-=f.offsetParent.offsetTop),l.clearRect(0,0,f.width,f.height),W(),T(),StickStatus.xPosition=F,StickStatus.yPosition=E,StickStatus.x=((F-m)/v*100).toFixed(),StickStatus.y=((E-C)/v*100*-1).toFixed(),StickStatus.cardinalDirection=D(),i(StickStatus))},!1),document.addEventListener("touchend",function(t){k=0,h&&(F=m,E=C);l.clearRect(0,0,f.width,f.height),W(),T(),StickStatus.xPosition=F,StickStatus.yPosition=E,StickStatus.x=((F-m)/v*100).toFixed(),StickStatus.y=((E-C)/v*100*-1).toFixed(),StickStatus.cardinalDirection=D(),i(StickStatus)},!1)):(f.addEventListener("mousedown",function(t){k=1},!1),document.addEventListener("mousemove",function(t){1===k&&(F=t.pageX,E=t.pageY,"BODY"===f.offsetParent.tagName.toUpperCase()?(F-=f.offsetLeft,E-=f.offsetTop):(F-=f.offsetParent.offsetLeft,E-=f.offsetParent.offsetTop),l.clearRect(0,0,f.width,f.height),W(),T(),StickStatus.xPosition=F,StickStatus.yPosition=E,StickStatus.x=((F-m)/v*100).toFixed(),StickStatus.y=((E-C)/v*100*-1).toFixed(),StickStatus.cardinalDirection=D(),i(StickStatus))},!1),document.addEventListener("mouseup",function(t){k=0,h&&(F=m,E=C);l.clearRect(0,0,f.width,f.height),W(),T(),StickStatus.xPosition=F,StickStatus.yPosition=E,StickStatus.x=((F-m)/v*100).toFixed(),StickStatus.y=((E-C)/v*100*-1).toFixed(),StickStatus.cardinalDirection=D(),i(StickStatus)},!1)),W(),T(),this.GetWidth=function(){return f.width},this.GetHeight=function(){return f.height},this.GetPosX=function(){return F},this.GetPosY=function(){return E},this.GetX=function(){return((F-m)/v*100).toFixed()},this.GetY=function(){return((E-C)/v*100*-1).toFixed()},this.GetDir=function(){return D()}};</script>	
  </head>
  <body> 
    	<table >
        <tr > 
          <td colspan=2>
            <div style="height:25px"><button onclick="openFullscreen()">Fullscreen</button><button onclick="rotateScreen()">Rotate</button></div> 
          </td>
        </tr>
        <tr> 
          <td>
              <div style="width:25px"></div> 
          </td>
            
            <td>
              <div id="joy1Div"></div> 
            </td>
            <td class="a"></br></br>
                X:<LABEL id="joy1X"  ></LABEL></br></br>
                Y:<LABEL id="joy1Y"  ></LABEL></br></br></br></br></br></br></br>
                &nbspX:<LABEL id="joy2X"  ></LABEL></br></br>
                &nbspY:<LABEL id="joy2Y"  ></LABEL></br></br>	
            </td>
            <td>        
                <div id="joy2Div"></div> 
            </td>
            
          </tr>
        </table>
		<script type="text/javascript">
function openFullscreen() {
	if(document.fullscreenElement)	{
	document.exitFullscreen();
	document.getElementsByTagName("button")[0].innerHTML="FullScreen";}
	else{
	document.getElementsByTagName("body")[0].requestFullscreen();
	document.getElementsByTagName("button")[0].innerHTML="Exit";	
	}
	screen.orientation.lock("landscape-primary");
}
function rotateScreen(){
	if (screen.orientation.type=="landscape-primary")screen.orientation.lock("landscape-secondary");
	else screen.orientation.lock("landscape-primary");
}
      function sendStick1(throttle,yaw) {
        document.getElementById("joy1X").innerHTML = yaw;
        document.getElementById("joy1Y").innerHTML = throttle;
        throttle=Math.min(100,Math.max(throttle,-100));yaw=Math.min(100,Math.max(yaw,-100));
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "Stick1?THROTTLE="+throttle+"&YAW="+yaw,false );
        xhttp.send();
      } 
      function sendStick2(pitch,roll) {
        document.getElementById("joy2X").innerHTML = pitch;
        document.getElementById("joy2Y").innerHTML = roll;
        pitch=Math.min(100,Math.max(pitch,-100));roll=Math.min(100,Math.max(roll,-100));
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "Stick2?PITCH="+pitch+"&ROLL="+roll, false);
        xhttp.send();
      } 

var tThrottle=0,tYaw=0,tPitch=0,tRoll=0;
var Joy1 = new JoyStick('joy1Div', {"autoReturnToCenter": false}, function(stickData1) {
    if(tThrottle!=stickData1.y||tYaw!=stickData1.x){
    sendStick1(stickData1.y,stickData1.x); 
    tThrottle=stickData1.y;tYaw=stickData1.x;
    }
});
var Joy2 = new JoyStick('joy2Div', {}, function(stickData2) {
    if(tPitch!=stickData2.y||tRoll!=stickData2.x){
    sendStick2(stickData2.y,stickData2.x); 
    tPitch=stickData2.y;tRoll=stickData2.x;
    }
});
	</script>
  </body>
</html>
)=====";
