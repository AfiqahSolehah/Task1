import java.net.*;
import java.io.*;

public class client{
	
	public static void main (String[] args) throws 

IOException{

		String sent ="Assalamualaikum";
		String receive ;

		Socket s = new Socket("192.168.182.132",6000);
		
		PrintWriter pr = new PrintWriter

(s.getOutputStream());
		pr.println(sent);
		pr.flush();
		
		
		InputStreamReader in = new InputStreamReader

(s.getInputStream());
		BufferedReader bf = new BufferedReader(in);
		
		receive = bf.readLine();
		System.out.println("Client : "+sent);
		System.out.println("Server : "+receive);
		
	}
}
