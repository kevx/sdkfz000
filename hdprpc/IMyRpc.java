package org.kevx;

import org.apache.hadoop.ipc.VersionedProtocol;

interface IMyRpc extends VersionedProtocol {
	static long versionID = 0;
	long getVal();
}