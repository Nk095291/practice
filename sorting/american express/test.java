import java.util.ArrayList;
import java.util.HashMap;

public class test{
    public static void main(String args[])
    {
        HashMap<Integer,Integer> map = new HashMap();
        for(int i =0;i<5;i+=1)
        {
            map.put(i,i*10);
        }
        ArrayList<Integer> ar = new ArrayList<>(map.keySet());
        for(int i =0;i<ar.size();i++)
            System.out.println(ar.get(i));
    }
}