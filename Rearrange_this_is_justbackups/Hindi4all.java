
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.util.Scanner;
import javax.net.ssl.HttpsURLConnection;
import java.nio.charset.StandardCharsets; 
import java.io.*;
public class Hindi4all  implements Runnable{
	private static int done=0;
	private String cname="";
	private String read(String name){
		try {
		FileReader fr = new FileReader(name);
		int r = 0;String read="";
		while ((r = fr.read()) != -1) {read+=(char) r;}
		return read;
	    }
	    catch(Exception e) {System.out.println("Exception Occurred:");e.printStackTrace();} 
	    return ""; 
	}
	private void writeIt(String name ,String data){
		if(data!=""&&data!=null&&name!=""&&name!=null) try {name=name.replace(".h4j",".java"); 
      	FileOutputStream fos = new FileOutputStream(name,false);//true to append
      	byte[] b =data.getBytes(); //converts string into bytes  
      	fos.write(b); //writes bytes into file  
      	fos.close(); //close the file  
    	}
    	catch(Exception e) {System.out.println("Exception Occurred:");e.printStackTrace();}  
		else {System.out.println("File name "+name+" or its Contents "+data+" not found (or is empty/null)");}
	}
	private String process(String data ){
		try{
			URL url = new URL("https://crptrest.000webhostapp.com/decode.php?lang=java");
			HttpsURLConnection http = (HttpsURLConnection)url.openConnection();
			http.setRequestMethod("POST");
			http.setDoOutput(true);
			http.setRequestProperty("Content-Type", "text/plain");
			byte[] out = data.getBytes(StandardCharsets.UTF_8);
			OutputStream stream = http.getOutputStream();
			stream.write(out);
			 InputStreamReader isr=new InputStreamReader(http.getInputStream());
			BufferedReader br = new BufferedReader(isr);
			StringBuffer sb =new StringBuffer();
			String input;			
	   		while ((input = br.readLine()) != null){
	      	sb.append(input+"\n");
	   		}
	   		br.close();
			http.disconnect();return sb.toString();
		} catch (MalformedURLException e) {
         System.out.println("Internet is not connected");System.exit(0);
      } catch (IOException e) {
         System.out.println("Internet is not connected");System.exit(0);
      }catch(Exception e) {System.out.println("Exception Occurred:");e.printStackTrace();}  
		return null;
	}
	@Override
	public void run() {writeIt(cname,process(read(cname)));this.done++;}
	Hindi4all(float hjghjhj){}
	public Hindi4all(String ... a){
	    for (int i=0;i<a.length;i++ )
	    {	//writeIt(a[i],process(read(a[i])));
	    	Hindi4all h=new Hindi4all(0.0f);
	    	h.cname=a[i];
	    	Thread t= new Thread(h);
		t.start();
    	}
    	String jkbk="";
    	while(true){jkbk=String.valueOf(this.done)+a.length;if(this.done>=a.length)break;else {}}
	    	//System.out.println("\tthis.done"+this.done+"\ta.length"+a.length);
	}
/*	public Hindi4all(int h4a,String ...a){
		for (int i=0;i<a.length;i++ )
	   {	//writeIt(a[i],process(read(a[i])));
	    	Hindi4all h=new Hindi4all(0.0f);
	    	h.cname=a[i];
	    	Thread t= new Thread(h);
		t.start();
    	}
    	String jkbk="";
    	while(true){jkbk=String.valueOf(this.done)+a.length;if(this.done>=a.length)break;else {}}
	   try {String [] cmm={"javac"};
	   File cmmf=new File(System.getProperty("user.dir"));
	   	Process pro=Runtime.getRuntime().exec(cmm,null,cmmf);}
	   Error :file not found even if file exists;

	   catch(Exception e){e.printStackTrace();}
	}*/
}