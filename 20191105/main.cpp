//输入某二叉树的前序遍历和中序遍历结果，请重建出该二叉树。假设输入的前序遍历和中序遍历结果重都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序{4,7,2,1,5,3,8,6},则重建二叉树并返回

/**
 * Definition for binary tree
 * struct TreeNode{
 * int val;
 * TreeNode* left;
 * TreeNode* right;
 * TreeNode(int x)
 * : val(x)
 * , left(NULL)
 * , right(NULL)
 * {}
 * };
 * */

class Solution{
  public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
      int vinlen = vin.size();
      int gen = 0;
      if(vinlen == 0)//递归结束条件
        return NULL;
      vector<int> pre_left,pre_right,vin_left,vin_right;
      TreeNode* head = new TreeNode(pre[0]);//根节点是前序序列的第一个元素
      for(int i = 0; i < vinlen; ++i)//找到中序序列中，根节点的位置，以gen为中心，将两个序列分为左半部和右半部
      {
        if(vin[i] == pre[0])
        {
          gen = i;//将根节点的位置保存在gen中
          break;
        }
      }
      for(int i = 0; i < gen; ++i)//将前序和中序序列的左半部元素存入新的数组中
      {
        vin_left.push_back(vin[i]);
        pre_left.push_back(pre[i + 1]);//前序遍历的左半部是从第二个元素算起，第一个元素为根节点
      }
      for(int i = gen + 1; i < vinlen; ++i)//将前序和中序序列的右半部元素存入新的数组中
      {
        vin_right.push_back(vin[i]);
        pre_right.push_back(pre[i]);
      }
      head->left = reConstructBinaryTree(pre_left,vin_left);//归并，直到新的数组中没有元素，递归结束
      head->right = reConstructBinaryTree(pre_right,vin_right);
      return head;
    }
};



//用两个栈来实现队列，完成pop和push的操作。队列元素为整型



//将元素压入stack1，将stack1栈顶的元素压入stack2
class Solution{
  public:
    void push(int node)//将元素压入stack1
    {
      stack1.push(node);
    }
    int pop()
    {
      if(stack2.empty())//若stack2为空，并且stack1不为空，将stack1中的元素压入Stack2
      {
        while(!stack1.empty())
        {
          stack2.push(stack1.top());
          stack1.pop();
        }
      }
      int tmp = stack2.top();
      stack2.pop();
      return tmp;
    }
  private:
    stack<int> stack1;
    stack<int> stack2;
};
