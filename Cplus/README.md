Some method:
1. 我们可以使用在指定string串中查找有无匹配字符，判断提取str是否为我们想要的字符串:/n
bool is_opera(string str){  
    return str.size()==1 && string("+-*/").find(str) != string::npos;
}
