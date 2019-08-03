//  Copyright (c) 2014 BA3, LLC. All rights reserved.
#pragma once

/** Conveys a specific type of map layer.*/
typedef NS_ENUM(NSInteger, MEMapType){
	/** Unknown map type. */
	kMapTypeUnknown,
	/** @warning Removed. */
    kMapTypeFileTerrain,
	/** @warning Removed. */
	kMapTypeFileTerrainTAWS,
	/** @warning Removed. */
	kMapTypeFileRaster,
	/** @warning Removed. */
	kMapTypeFileRasterPVR,
	/** @warning Removed. */
	kMapTypeFileRasterPVR_RAW,
	/** A map in which data will be supplied by an METileProvider-derived object.*/
    kMapTypeVirtualRaster,
	/** A multi-frame animated map in which data will be supplied by an METileProvider-derived object.
	@warning Removed.*/
	kMapTypeVirtualRasterAnimated,
	/** @warning Removed. */
	kMapTypeFileVector,
	/** In-memory vector map in which lines, polygons, and vector markers are dynamically added or removed. */
	kMapTypeDynamicVector,
	/** Disk-based marker map generated by AltusMarker.*/
    kMapTypeFileMarker,
	/** Instructs the mapping engine to create and write out a clustered marker map with the supplied markers. */
	kMapTypeFileMarkerCreate,
	/** In-memory clustered marker map. Added using an array of MEMarker objects. Marker images will be requested as needed from the delegate. */
	kMapTypeMemoryMarker,
	/** In-memory dynamic marker map to which markers can be added and later have their positions updated. Marker images are supplied when added or pre-cached. */
	kMapTypeDynamicMarker,
	/**  Disk-based mbtiles map generated with the MapBox TileMill program. */
	kMapTypeFileMBTiles,
	/** Vector map whose geometry is supplied by an METileProvider-derived object. */
	kMapTypeVirtualVector,
	/** Marker map whose data is supplied by an METileProvider-derived object. */
    kMapTypeVirtualMarker,
	/** @warning Removed. */
	kMapTypeFileTerrain3D,
	/** Terrain map whose height data is supplied by an METileProvider-derived object. */
	kMapTypeVirtualTerrain,
	/** In-memory model map in which 3D models are dynamically added or removed. */
	kMapTypeDynamicModel3D,
	/** Used to create bilinear filtered layers from a sparse data set and color bar. */
	kMapTypeWeatherGrid,
	/** Not yet documented. */
	kMapTypeDataGrid,
	/** A map package produced by Altus Package.*/
	kMapTypePackage,
	/** A terrain mesh layer that is derived from the data of a vertual terrain layer or terrain package.*/
	kMapTypeTerrainMeshMap,
};


/**Enumeration of different map content types.*/
typedef NS_ENUM(NSInteger, MEMapContentType){
	/**The map is comprised of different imagery at different zoom levels. This would apply to almost all internet-based street maps where the level of detail of the data increases as you zoom in. This would not apply to most aerial or satellite image. When using content of this type, you will might want to set tileLevelBiasing to 1.0 which will force tiles to always be of the same level (at a memory cost).*/
	kZoomDependent,
	/**The map is created by sampling a large fixed raster data set (satellite images, scanned FAA sectionals, aerial photographs, etc.).*/
	kZoomIndependent
};

/**Enumeration of different map loading strategies.*/
typedef NS_ENUM(NSInteger, MEloadingStrategy){
	/**The currently viewed area of the map is loaded from the lowest detail to the highest. This costs more in terms of loading time but if maps are local, can result in a smoother feel when zooming and panning.*/
	kLowestDetailFirst,
	/**Only the detail level currently in view is loaded. Generally faster for internet-based virtual maps.*/
	kHighestDetailOnly,
	/**DOCTBD*/
    kPreloaded,
	/**DOCTBD*/
    kHybrid,
	/**DOCTBD*/
    kNone
};

/**Enumeration of different marker map loading strategies.*/
typedef NS_ENUM(NSInteger, MEMarkerImageLoadingStrategy){
	/**Marker map delegate will receive requests for images, as-needed, on a background thread. Good for when you have hundreds of thousands of markers and loading speed is not super important.*/
	kMarkerImageLoadingAsynchronous,
	/**Marker map delegate will receive requests for images, as-needed, on the primary thread. Good for when you have hundreds of markers and loading speed is important.*/
	kMarkerImageLoadingSynchronous,
	/**Marker images are pre-cached with the mapping engine. There is no separate loading step. This is good for limited use when you need the fastest possible display.*/
	kMarkerImageLoadingPrecached
};

/**Enumeration of data types for tile images used in the METileProviderRequest object*/
typedef NS_ENUM(NSInteger, MEImageDataType){
	/** Image type is unknown. */
    kImageDataTypeUnknown,
	/** Image data is PNG format. */
    kImageDataTypePNG,
	/** Image data is JPG format. */
    kImageDataTypeJPG,
	/** Image data is 32 bits per pixel, with 8 bits each for Red, Green, Blue, and Alpha. */
    kImageDataTypeRGBA8888
};

/**Enumeration of tile provider response types.*/
typedef NS_ENUM(NSInteger, METileProviderResponse){
	/** Default value of response. */
	kTileResponseUnknown,
	/** The tile has no content, but does have children. So continue requesting its children. */
	kTileResponseTransparentWithChildren,
	/** The tile has no content, and no children. Make no further requests. */
	kTileResponseTransparentWithoutChildren,
	/** The tile is not available at this time. Do not request it again. */
	kTileResponseNotAvailable,
	/** Tile is available and its data is being provided as a UIImage object. */
	kTileResponseRenderUIImage,
	/** Tile is available and its data is being provided as a NSData object. */
	kTileResponseRenderNSData,
	/** Tile is available and its data is being provided as path to a file. */
	kTileResponseRenderFilename,
	/** Tile is available and its data is being provided as a void pointer to a block of memory. */
	kTileResponseRenderImageData,
	/** Tile is available and its data should be sourced from a previously cached image. */
	kTileResponseRenderNamedCachedImage,
	/** Tile is not longer needed. Make no further requests for it. */
	kTileResponseWasCancelled
};

/**Specifies how marker rotations are rendered by the engine.*/
typedef NS_ENUM(NSInteger, MEMarkerRotationType){
	/** Markers will always be aligned to the edge of the screen no matter how the map is oriented. */
	kMarkerRotationScreenEdgeAligned,
	/** The marker will always be oriented relative to North no matter how the map is oriented.*/
	kMarkerRotationTrueNorthAligned
};

/**Specifies map package content.*/
typedef NS_ENUM(NSInteger, MEPackageType){
	/** Package contains a unknown content type. */
	kPackageTypeUnknown=0,
	/** Package contains raster images as either PNG or JPG images. */
    kPackageTypeRaster=1,
	/** Package contains terrain data as 2-byte signed integers produced by AltusTerrain. */
    kPackageTypeTerrain=4,
	/** Package contains vector tiles produced by AltusVector. */
    kPackageTypeVector=6
};

/**Enumeration of different lighting types.*/
typedef NS_ENUM(NSInteger, MELightingType){
	/** Lighting is modeled on dynamic natural sun light and realistic atmosphere.*/
	kLightingTypeRealistic,
	/** Lighting is modeled on a simple constant light source.*/
	kLightingTypeClassic
};

/**Enumeration of different lighting direction types.*/
typedef NS_ENUM(NSInteger, MELocationType){
	/** Sun is located directly above a geographic location. */
	kLocationTypeAbsolute,
	/** Sun is always a given offset from the current camera placement. */
	kLocationTypeRelative
};

/**Enumeration of possible tile regions.*/
typedef NS_ENUM(NSInteger, METileRegion){
	/** The initial root tile or beginning node in a tile tree.*/
    kTileRegionRoot,
	/** The bottom of the tile has latitude >= -80 degrees latitude the top of the tile has latitude <= 80 degrees latitude.*/
    kTileRegionCenter,
	/** The tile is located North of 80.0 degrees latitude.*/
    kTileRegionNorth,
	/** The tile is located South of -80.0 degrees latitude.*/
    kTileRegionSouth
};