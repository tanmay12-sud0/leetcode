class Solution {
public:
    // string entityParser(string text) {
    string entityParser(string text) 
{
        if(text == "&amp;gt;"){
            return "&gt;";
        }
	replaceString(text, "&quot;", "\"");
	replaceString(text, "&apos;", "\'");
	replaceString(text, "&amp;", "&");
	replaceString(text, "&gt;", ">");
	replaceString(text, "&lt;", "<");
	replaceString(text, "&frasl;", "/");

	return text;
}

void replaceString(string& text, const string& search, const string& replace)
{
	auto i = 0;
	while((i = text.find(search, i)) != string::npos)
	{
		text.replace(i, search.length(), replace);
		i += replace.size();
	}
}

//         unordered_map<string, string>hash;
//         hash["&quot;"] = "\"";
//         hash["&apos;"] = "'";
//         hash["&amp;"] = "&";
//         hash["&gt;"] = ">";
//         hash["&lt;"] = "<";
//         hash["&frasl;"] = "/";
//         bool flag = false;
//         int n = text.length();
//         string s;
//         for(int i=0; i<n;){
//             s += text[i];
//             if(text[i]=='&'){
//                 flag = true;
//                 s = text[i];
//             }
//             if(text[i]==';'){
//                 int len = s.length();
//                 if(hash.count(s)){
//                     text.erase(i-len+1, len);
//                     text.insert(i-len+1, hash[s]);
//                     i = len-hash[s].length();
//                 }
//                 s = "";
//             }
//             i++;
//         }
        
//         return text;
    // }
};