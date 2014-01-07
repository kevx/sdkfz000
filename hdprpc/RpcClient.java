package org.kevx;

import java.io.IOException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.UnknownHostException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.ipc.AvroRpcEngine;
import org.apache.hadoop.ipc.RPC;

public class RpcClient {

	public static void main(String[] args) throws UnknownHostException {
		InetSocketAddress isa = new InetSocketAddress(InetAddress.getLocalHost(), 6666);
		
		AvroRpcEngine rpcEg = new AvroRpcEngine();
		Configuration conf = new Configuration();
		
		//conf.setClass("rpc.engine.org.kevx.IMyRpc", rpcEg.getClass(), IMyRpc.class);
		try {
			IMyRpc myRpc = RPC.getProxy(IMyRpc.class, 0, isa, conf);
			
			for (int i = 0; i < 10; i++) {
				System.out.println(myRpc.getVal());
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
