import random

print("欢迎来到猜数字小游戏！")
print("我已经想好了一个 1 到 100 之间的整数。")
print("你有 7 次机会来猜对它。")

answer = random.randint(1, 100)
max_tries = 7
tries = 0

while tries < max_tries:
    try:
        guess = int(input(f"\n第 {tries + 1} 次请输入你的猜测："))
    except ValueError:
        print("请输入一个有效的整数！")
        continue

    tries += 1

    if guess < answer:
        print("太小了！")
    elif guess > answer:
        print("太大了！")
    else:
        print(f"恭喜你，猜对了！答案就是 {answer}")
        print(f"你一共用了 {tries} 次就猜中了！")
        break
else:
    print("\n很遗憾，次数用完了。")
    print(f"正确答案是：{answer}")

print("\n游戏结束，感谢游玩！")