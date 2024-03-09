
select name,sum(amount) as balance from users
inner join transactions on users.account=transactions.account
group by name
having balance>10000