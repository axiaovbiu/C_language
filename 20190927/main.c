#include<stdio.h>
#include<unistd.h>
//进度条小代码
int main()
{
  const char* label = "/-\\|";//动态旋转效果
  char buf[1024] = {0};
  int i = 0;
  for(; i <100;++i)
  {
    buf[i] = '#';
    if(i<25)
    {
       printf("[%d%%][%c]\033[31m[%s]\r\033[0m",i,label[i % 4],buf);// \033[ 打开前景色样式  \033[0m 关闭样式
    }
    else if(i< 90&& i > 25)
    {
       printf("[%d%%][%c]\033[33m[%s]\r\033[0m",i,label[i % 4],buf);
    }
    else 
    {
      printf("[%d%%][%c]\033[32m[%s]\r\033[0m",i,label[i % 4],buf);
    }
   fflush(stdout);//对标准流清理，及时打印数据到屏幕上
   usleep(100 * 1000);
  }
  return 0;
    
}
