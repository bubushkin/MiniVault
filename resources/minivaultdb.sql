create table if not exists mv_agent
(
    id           int auto_increment
        primary key,
    ip_address   varchar(40)          not null,
    uuid         varchar(256)         not null,
    last_contact timestamp            null,
    disown       tinyint(1) default 0 not null,
    constraint mv_agent_pk
        unique (ip_address)
);

create table if not exists mv_secret
(
    id     int auto_increment
        primary key,
    cname  varchar(128) not null,
    secret int          null,
    constraint mv_secret_pk_2
        unique (cname)
);

create table if not exists mv_grant
(
    agent_id  int not null,
    secret_id int not null,
    constraint mv_grant_mv_agent_id_fk
        foreign key (agent_id) references mv_agent (id),
    constraint mv_grant_mv_secret_id_fk
        foreign key (secret_id) references mv_secret (id)
);


