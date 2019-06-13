/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Worker.cpp
 * Author: cpu10855
 * 
 * Created on June 11, 2019, 10:25 AM
 */

#include "Worker.h"

///--- Worker Code

void Worker::run(){
	Poco::Notification::Ptr pNf(_queue.waitDequeueNotification()); // does not have time out
	while(pNf){
		WorkNotification* job = dynamic_cast<WorkNotification*>(pNf.get());
		if (job){ // handle 
			Poco::FastMutex::ScopedLock lock(_mutex);
			if (job->isRead()){ // for read process
//				switch (job.type()){
//					case SubKC::DB_TYPE::USER:
//						_db->loadUser()
//				}
			} else { // for write process
				switch (job->type()){
					case SubKC::DB_TYPE::USER:
						_db->storeUser(job->key(), job->value());
						break;
				}
			}
		}
		
		pNf = _queue.waitDequeueNotification();
	}
}

