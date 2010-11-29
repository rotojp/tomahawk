#include "databasecommand_loadfile.h"

#include "databaseimpl.h"
#include "tomahawk/collection.h"


DatabaseCommand_LoadFile::DatabaseCommand_LoadFile( const QString& id, QObject* parent )
    : DatabaseCommand( parent )
    , m_id( id )
{
}


void
DatabaseCommand_LoadFile::exec( DatabaseImpl* dbi )
{
    QVariantMap r;
    // file ids internally are really ints, at least for now:
    bool ok;
    do
    {
        unsigned int fid = m_id.toInt( &ok );
        if( !ok )
            break;

        r = dbi->file( fid );
    } while( false );

    emit result( Tomahawk::result_ptr( new Tomahawk::Result( r, Tomahawk::collection_ptr() ) ) );
}
