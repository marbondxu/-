using System;

class Program
{
    static void Main()
    {
        Random rand = new Random();
        int target = rand.Next(1, 101);
        int guess = 0;
        int count = 0;

        Console.WriteLine("猜数字游戏开始！请输入 1~100 之间的数字：");

        while (guess != target)
        {
            if (!int.TryParse(Console.ReadLine(), out guess))
            {
                Console.WriteLine("请输入有效数字！");
                continue;
            }

            count++;
            if (guess > target)
                Console.WriteLine("太大了，再试试！");
            else if (guess < target)
                Console.WriteLine("太小了，再试试！");
            else
                Console.WriteLine($"恭喜你，猜中了！共用了 {count} 次。");
        }
    }
}