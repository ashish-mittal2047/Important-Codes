
class node
{
	public:
		char data;
		unordered_map<char,node*> h;
		bool isTerminal;
		node(char ch)
		{
			data = ch;
			isTerminal = 0;
		}
};

