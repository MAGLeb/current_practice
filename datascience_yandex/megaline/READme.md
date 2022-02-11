## Project description
The company (operator Megaline) offers its clients two prepaid plans, Surf and Ultimate. The commercial department wants to know which of the plans is more profitable in order to adjust the advertising budget.

I carry out a preliminary analysis of the plans based on a relatively small client selection. I'll have the data on 500 Megaline clients: who the clients are, where they're from, which plan they use, and the number of calls they made and text messages they sent in 2018. My job is to analyze clients' behavior and determine which prepaid plan is more profitable.

![Image of table](https://i.ibb.co/y6Tr1YN/image.png)

### Description of the data
- **user_id** — unique user identifier
- **first_name** — user's name<br> 
- **last_name** — user's last name<br> 
- **age** — user's age (years)<br> 
- **reg_date** — subscription date (dd, mm, yy)<br> 
- **churn_date** — the date the user stopped using the service (if the value is missing, the calling plan was being used when this database was extracted)<br> 
- **city** — user's city of residence<br> 
- **plan** — calling plan name<br> 
- **The** calls table (data on calls):<br> 
- **id** — unique call identifier<br> 
- **call_date** — call date<br> 
- **duration** — call duration (in minutes)<br> 
- **user_id** — the identifier of the user making the call<br> 
- **The** messages table (data on texts):<br> 
- **id** — unique text message identifier<br> 
- **message_date** — text message date<br> 
- **user_id** — the identifier of the user sending the text<br> 
- **The** internet table (data on web sessions):<br> 
- **id** — unique session identifier<br> 
- **mb_used** — the volume of data spent during the session (in megabytes)<br> 
- **session_date** — web session date<br> 
- **user_id** — user identifier<br> 
- **The** plans table (data on the plans):<br> 
- **plan_name** — calling plan name<br> 
- **usd_monthly_fee** — monthly charge in US dollars<br> 
- **minutes_included** — monthly minute allowance<br> 
- **messages_included** — monthly text allowance<br> 
- **mb_per_month_included** — data volume allowance (in megabytes)<br> 
- **usd_per_minute** — price per minute after exceeding the package limits (e.g., if the package includes 100 minutes, the 101st minute will be charged)<br> 
- **usd_per_message** — price per text after exceeding the package limits<br> 
- **usd_per_gb** — price per extra gigabyte of data after exceeding the package limits (1 GB = 1024 megabytes)<br> 

