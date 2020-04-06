import java.util.*;
import java.io.*;

 class spoj
{

	public static void main(String[] args)
	{
		
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
    		boolean prime[]=new boolean[1000001];
		Arrays.fill(prime,true);
		for(int p=2;p*p<1000001;p++)
		{
			if(prime[p]==true)
			{
				for(int j=p*p;j<1000001;j+=p)
				{
					prime[j]=false;
				}
			}
		}
		while(t-->0)
		{
			long x=sc.nextLong();
			long k=sc.nextLong();
			long total=0;
			boolean flag=false;
			
				for(int i=2;i<1000001;i++)
				{
					if(x==1)
						break;	
					if(prime[i])
					{
						while(x%i==0)
						{
							x=x/i;
							total++;
							if(x!=1 && total+1==k)
							{
							    System.out.println(1);
								flag=true;
								break;
							}
							if(total==k)
							{
								System.out.println(1);
								flag=true;
								break;
							}
						}
						
					}
					if(flag)
						break;

				}
				if(!flag)
				{
					System.out.println(0);
				}
			


		}


	}
}