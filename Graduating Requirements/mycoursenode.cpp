class mycoursenode{
public:
	string coursename;
	vector<string> requirecourse;
	mycoursenode(string coursename, vector<string> r)
	{
		this->coursename = coursename;
		this->requirecourse = r;
	}
};
