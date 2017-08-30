build:
	docker build -t node_ctp:0.1 .

start:
	docker-compose up -d

enter:
	docker exec -it node_ctp bash