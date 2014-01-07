package org.kevx;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.ipc.ProtocolSignature;
import org.apache.hadoop.ipc.RPC;

public class HdpRpcSvr {

	private static class MyRpc implements IMyRpc {
		@Override
		public long getVal() {
			return System.currentTimeMillis();
		}

		@Override
		public long getProtocolVersion(String protocol, long clientVersion)
				throws IOException {
			return 0;
		}

		@Override
		public ProtocolSignature getProtocolSignature(String protocol,
				long clientVersion, int clientMethodsHash) throws IOException {
			return ProtocolSignature.getProtocolSignature(this, protocol, 0, 0);
		}
	}
	
	public static void main(String[] args) {
//		/AvroRpcEngine rpcEngine = new AvroRpcEngine();
		MyRpc inst = new MyRpc();
		
		Configuration conf = new Configuration();
		//conf.setClass("rpc.engine.org.apache.hadoop.ipc.AvroRpcEngine", MyRpc.class, IMyRpc.class);
		
		try {
			RPC.Server s = RPC.getServer(IMyRpc.class, inst, "0.0.0.0", 6666, conf);
			s.start();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(IMyRpc.class.getName());
	}
}
