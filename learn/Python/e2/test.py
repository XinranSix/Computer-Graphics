import pandas as pd

# 读取数据文件
data = pd.read_excel("demo-20230529-144812.xlsx", sheet_name="Sheet3")

# 日常流量与企业类型的关系
average_flow_by_type = data.groupby("企业类型")["日常流量"].mean()
print("日常流量与企业类型的关系:")
print(average_flow_by_type)

# 日常流量与级别的关系
average_flow_by_level = data.groupby("级别")["日常流量"].mean()
print("日常流量与级别的关系:")
print(average_flow_by_level)

# 企业类型与日均订单量的关系
average_orders_by_type = data.groupby("企业类型")["日均订单量"].mean()
print("企业类型与日均订单量的关系:")
print(average_orders_by_type)

# 日均订单量与级别的关系
average_orders_by_level = data.groupby("级别")["日均订单量"].mean()
print("日均订单量与级别的关系:")
print(average_orders_by_level)
# 企业类型与级别的关系
cross_table = pd.crosstab(data["企业类型"], data["级别"])
print("企业类型与级别的关系:")
print(cross_table)
