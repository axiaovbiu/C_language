//在一个二维数组中(每个一位数组的长度相同)，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断你数组中是否有该整数。
class Solution{
  public:
    bool Find(int target,vector<vector<int>> array)
    {
      int rowcnt = array.size();
      int colcnt = array[0].size();
      int row = 0;
      int col = colcnt - 1;
      while(row < rowcnt && col >= 0)
      {
        if(array[row][col] < target)//定位在矩阵的右上角，与target比较，若小于则向下移动
        {
          row++;
        }
        else if(array[row][col] > target)//若大于则向左移动
        {
          col--;
        }
        else
        {
          return true;
        }
    }
      return false;
};



//请实现一个函数，将一个字符串中的每个空格替换成”%20”。例如，当字符串为We Are Happy，则替换之后的字符串为We%20Are%20Happy。
class Solution{
  public:
    void replaceSpace(char *str,int length)
    {
      if(nullptr == str || length < 0)
        return;
      int len = 0;//记录数组中元素个数
      int spacecnt = 0;//记录数组中空格的个数
      for(int i = 0; str[i] != '\0'; ++i)
      {
        if(' ' == str[i])
        spacecnt++;
        len++;
      }
      int newlen = len + spacecnt * 2;//填充后数组的大小
      if(newlen + 1 > length)
        return;//扩大后的数组大小不能大于总大小
      while(newlen >= 0 && len >= 0)
      {
        if(str[len] == ' ')
        {
          str[newlen--] = '0';
          str[newlen--] = '2';
          str[newlen--] = '%';
        }
        else{
          str[newlen] = str[len];
          newlen--;
        }
        len--;
      }
    }
};



//输入一个链表，按链表从尾到头的顺序返回一个ArrayList
/*
 *struct ListNode{
        int val;
        struct ListNode *next;
        ListNode(int x)
        : val(x)
        , next(NULL)
        {}
 };
 * */
class Solution{
  public:
    vector<int>printListFromTailToHead(ListNode* head)
    {
      vector<int> result;
      stack tmp;
      ListNode* phead = head;
      while(phead)//将链表中的元素压入栈,因为栈中元素先入后出，可将链表中的元素逆向存入
      {
        tmp.push(phead->val);
        phead = phead->next;
      }
      int len = tmp.size();
      for(int i = 0; i < len; ++i)//将栈中元素插入数组中
      {
        result.push_back(tmp.top())
          tmp.pop();
      }
      return result;
    }
};
