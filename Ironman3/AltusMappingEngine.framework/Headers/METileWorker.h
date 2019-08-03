//  Created by Bruce Shankle on 5/30/14.
#pragma once
#import <Foundation/Foundation.h>
#import "METileProvider.h"
#import "MEPackage.h"

//Forward declarations
@class METileFactory;

/**
 Serves as base class for an object that does the work of downloading, retrieving, or creating a tile TileWorkers do their work in the context of a TileFactory.
 You should create a class that extends this class and overrides the doWork function.*/
@interface METileWorker : NSObject

/**The serial queue on which this worker does work.*/
@property (retain) dispatch_queue_t serialQueue;

/**The queue on which the worker works. Default is DISPATCH_QUEUE_PRIORITY_DEFAULT.
 You can set this to:
 DISPATCH_QUEUE_PRIORITY_HIGH
 DISPATCH_QUEUE_PRIORITY_DEFAULT
 DISPATCH_QUEUE_PRIORITY_LOW
 DISPATCH_QUEUE_PRIORITY_BACKGROUND*/
@property (assign) dispatch_queue_priority_t targetQueuePriority;

/**True if the worker is busy.*/
@property (assign) BOOL isBusy;

/**Reference to the owning tile factory, this must be weak to prevent
 circular retain issues. The mapping engine will keep a reference to the tile
 factory as long as the map layer it is providing resources for is still loaded.*/
@property (weak) METileFactory* tileFactory;

-(void) startTile:(METileProviderRequest *) meTileRequest
		cacheData:(NSData*) cacheData;

/**Over-ride this function in your class to do the work of getting a tile. This function
 will be called from a background thread and will only be called if the resource
 is actually needed by the mapping engine.*/
-(NSData*) doWork:(METileProviderRequest *) meTileRequest
		cacheData:(NSData*) cacheData;


/**Unpacks a UIImage into RGBA8888 format and populates the specified tile request object appropriately so the image data can be returned uncompressed to the mapping engine.*/
-(BOOL) unpackUIImage:(UIImage*) image
		meTileRequest:(METileProviderRequest*) meTileRequest;

/**Converts an NSData object into a UIImage and then unpacks the image into RGBA8888 format and populates the specified tile request object appropriately so the image data can be returned uncompressed to the mapping engine.*/
-(BOOL) unpackImageData:(NSData*) data
		  meTileRequest:(METileProviderRequest*) meTileRequest;
@end
