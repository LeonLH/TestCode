function split(str, sep)
	local nFindStartIndex = 1
	local nSplitIndex = 1
	local nSplitArray = {}
	while true do
		local nFindLastIndex = string.find(str, sep, nFindStartIndex)
		if not nFindLastIndex then
			nSplitArray[nSplitIndex] = string.sub(str, nFindStartIndex, string.len(str))
			break
		end

		nSplitArray[nSplitIndex] = string.sub(str, nFindStartIndex, nFindLastIndex - 1)
		nFindStartIndex = nFindLastIndex + string.len(sep)
		nSplitIndex = nSplitIndex + 1
	end

	return nSplitArray
end

function getOpenSepConnection(mysql_conf)
	local openSepCon = {}
	-- mysql_conf 格式： 127.0.0.1,3306,ttmgrportal_year_2018,root,mysql.rzrk,
	print("getOpenSepConnection colse g_connections size: " .. mysql_conf)
	local mysqlTable = split(mysql_conf,",")
	local dbName = mysqlTable[3]
	for conf, con in pairs(g_connections) do
		local openDB = split(conf,",")
		local openDBName = openDB[3]
		print("openDBName " .. openDBName)
		local vecName = split(openDBName, "_")
		print("vecName colse g_connections size: " .. tostring(#vecName))
		if #vecName > 1 and vecName[1] == 'ttmgrportal'then
			table.insert(openSepCon, con)
		end
	end
	return openSepCon
end

mysql_conf = '127.0.0.1,3306,ttmgrportal_year_2018,root,mysql.rzrk,'
g_connections = {}
g_connections[mysql_conf] = 111

getOpenSepConnection(mysql_conf)
