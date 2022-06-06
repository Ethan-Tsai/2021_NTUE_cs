//  程式設計二，第一次上機考試 ，第九題 (2/6/1/2分)
// 

//  假設一個鏈結串列包含三個節點，從頭開始依序放置的內容式 5 8 3
//  請建立這個鏈結串列，並輸出其內容
//  節點的結構名稱維 TNode，裡面兩個成員變數，儲存數值的 int 型別整數與指向 TNode 的指標變數
//  計分方式 (1 跟 2 請二擇一撰寫)
//      1.(2 分) 單純以 TNode 宣告三個結構變數，並手工的方式一個串一個，完成該鏈結串列
//      2.(6 分) 以詢問的方式，先問要建立的節點個數，以 malloc 取得一個節點，
// 				 並建立一個節點的鏈結串列，完成 head、tail 的設定
//               然後以 for 迴圈，利用 malloc 取得其他的節點，輸入並完成連鏈結串列
//      以上兩個都必須依序輸出節點的內容，無論你用何種方式，
//   	3.(1 分) 但如果以 while 迴圈，依序的經過每一個節點並輸出其內容則再多一分
//   	4.(2 分) 能以 while 迴圈，依序地釋放每一個節點
//   

// 詢問要建立幾個節點，並輸入每一個節點要儲存的內容
// 參考以下的輸出完成鏈結串列。
//
// 計分方式：4 分 : 完成節點的建立與輸出，而且節點的取得是使用 malloc，不能使用一般的結構變數 
//           2 分 : 節點的釋放，必須使用迴圈來釋放不得使用暴力法
// -------以下為 2 分的輸出參考  --------
// 第 1 個 node 的內容 : 5
// 第 2 個 node 的內容 : 8
// 第 3 個 node 的內容 : 4

// -------以下為 6 + 1 + 2 分的輸出參考  --------
// 請輸入需要幾個 node : 3
// 請輸入第 1 個 node 的內容 : 5
// 請輸入第  2 個 node 的內容 : 8
// 請輸入第  3 個 node 的內容 : 4
// 第  1 個 node 的內容是   5
// 第  2 個 node 的內容是   8
// 第  3 個 node 的內容是   4
//
// 釋放節點的內容是  5
// 釋放節點的內容是  8
// 釋放節點的內容是  4
// 共釋放了  3 個 node
//

#define EX9
#ifdef EX


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

// 宣告 TNode
typedef struct TNode {
	int num;
	struct TNode *Link;
} NODE, *PNODE;

int main(void)
{

	printf("方法二:\n");
	int i, num, in;
	PNODE pHead, pTail, pGet;
	pHead = pTail = NULL;
	printf("請輸入需要幾個 node : "); scanf("%d", &num);
	if ((pHead = (PNODE)malloc(sizeof(NODE))) == NULL) { 
		printf("記憶體不足\n"); exit(0);
	}
	printf("請輸入第1個node 的內容: "); scanf("%d", &in);
	pHead->num = in; pHead->Link = NULL;
	pTail = pHead;
	for (i = 1; i < num; i++) { 
		if ((pGet = (PNODE)malloc(sizeof(NODE))) == NULL) {
			printf("記憶體不足\n"); exit(0);
		}
		printf("請輸入第%d個node 的內容: ", i + 1); scanf("%d", &in);
		pGet->num = in; pGet->Link = NULL;	
		pTail->Link = pGet; pTail = pGet;	
	}
	pGet = pHead; i = 1;
	int tot = 0;
	while (pGet != NULL) { 
		printf("第%d個node 的內容是 %d\n", i, pGet->num);
		pGet = pGet->Link; i++;
		tot++;
	}
	printf("共釋放了%d個node\n", tot);
	system("pause"); return(0);
}
#endif



