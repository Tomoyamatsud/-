/* ソートの練習 */
/* コマンドライン引数で、選択できるようにする。 */
/* 数値列の生成はどうするか？ */

#include "stdio.h"
#include "stdlib.h"

/* 外部関数の定義 */

/* 内部関数の定義 */
void getRandomNumbers( int [] );
void BubbleSort( int [] );
void BucketSort( int [] );

/* 定義値 */
#define ARRAY_MAX 15 // ソート対象の配列最大数
#define BUCKET_MAX_SIZE 1000 //バケットソートの配列

int main( int argc, char *argv[] )
{
  int randomNumbers[ARRAY_MAX];
  int sortedNumbers[ARRAY_MAX];
  int n; //配列の添字

  // ローカルの配列にランダムな数字を格納する
  getRandomNumbers( randomNumbers );

  // 配列のソート
  //  BubbleSort( randomNumbers );
  BucketSort( randomNumbers );
  // 配列の要素を全て表示する
  for( n = 0; n < ARRAY_MAX; n++ )
    {
      printf("%d \n", randomNumbers[n]);
    }
  printf("\n");

  return 0;
}

void getRandomNumbers( int array[] )
{
  int n; //配列の添字

  for( n = 0; n < ARRAY_MAX; n++ )
  {
    array[n] = rand() % 500;
  }
  
  return;
}

void BubbleSort( int Array[] )
{
  int n, k; // 配列の添字
  int swap;

  for( n = 0; n < ARRAY_MAX; n++ )
  {
    for( k = 0; k < ARRAY_MAX; k++ )
    {
      if( Array[n] < Array[k] )
      {
	swap = Array[n];
	Array[n] = Array[k];
	Array[k] = swap;
      }
    }
  }  

  return;
}

void BucketSort( int Array[] )
{
  int Bucket[BUCKET_MAX_SIZE];
  int n,m;

  n = m = 0;

  for( n = 0; n < BUCKET_MAX_SIZE; n++ )
    {
      Bucket[n] = 0; // バケットの要素を0にする
    }
    
  for( n = 0; n < ARRAY_MAX; n++ )
    {
      Bucket[ Array[n] ] = Array[n];
    }

  for( n = 0; n < BUCKET_MAX_SIZE; n++ )
    {
      if( Bucket[n] != 0 )
	{
	  Array[m] = Bucket[n];
	  m++;
	}
    } 
  
  return;
}
