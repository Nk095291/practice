import java.util.*;
public class diff{
    public static void main(String args[]){
        Scanner scn = new Scanner(System.in);
        int t= scn.nextInt();
        
        while(t>0)
        {
            int n= scn.nextInt();
            int[]ar = new int[n];
            for(int i=0;i<n;i++)
                ar[i]=scn.nextInt();
            System.out.println(solve(ar));
            t--;
        }
    }
    public static int solve(int[]ar)
    {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i =0;i<ar.length;i++)
            map.put(ar[i],0);
        for(int i =0;i<ar.length;i++)
        {
            int x = ar[i];
            if((x&1)==1)
            {
                map.put(x,map.get(x)+1);
                if(map.get(x)>1)
                    return 0;

                    if(map.containsKey(x*2)==false)
                        map.put(2*x,1);
                    else
                        map.put(2*x,map.get(2*x)+1);

                if(map.get(2*x)>1)
                return 0;

            }
            else{
                while((x%2)==0)
                {
                    if(map.containsKey(x)==false)
                    map.put(x,1);
                    else
                    map.put(x,map.get(x)+1);
                    if(map.get(x)>1)
                        return 0;
                    x=x/2;
                }
                if(map.containsKey(x)==false)
                map.put(x,1);
                else
                map.put(x,map.get(x)+1);
                if(map.get(x)>1)
                return 0;
                
            }
        }

        ArrayList<Integer> res = new ArrayList<>(map.keySet());
        int mini = res.get(res.size()-1)-res.get(0);
        for(int i =0;i<res.size()-1;i++)
        {
            mini = Math.min(mini, res.get(i+1)-res.get(i));
        }
        return mini;
    }
}