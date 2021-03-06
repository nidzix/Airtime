<?php



/**
 * This class defines the structure of the 'cc_playlist' table.
 *
 *
 *
 * This map class is used by Propel to do runtime db structure discovery.
 * For example, the createSelectSql() method checks the type of a given column used in an
 * ORDER BY clause to know whether it needs to apply SQL to make the ORDER BY case-insensitive
 * (i.e. if it's a text column type).
 *
 * @package    propel.generator.airtime.map
 */
class CcPlaylistTableMap extends TableMap {

	/**
	 * The (dot-path) name of this class
	 */
	const CLASS_NAME = 'airtime.map.CcPlaylistTableMap';

	/**
	 * Initialize the table attributes, columns and validators
	 * Relations are not initialized by this method since they are lazy loaded
	 *
	 * @return     void
	 * @throws     PropelException
	 */
	public function initialize()
	{
	  // attributes
		$this->setName('cc_playlist');
		$this->setPhpName('CcPlaylist');
		$this->setClassname('CcPlaylist');
		$this->setPackage('airtime');
		$this->setUseIdGenerator(true);
		$this->setPrimaryKeyMethodInfo('cc_playlist_id_seq');
		// columns
		$this->addPrimaryKey('ID', 'DbId', 'INTEGER', true, null, null);
		$this->addColumn('NAME', 'DbName', 'VARCHAR', true, 255, '');
		$this->addColumn('STATE', 'DbState', 'VARCHAR', true, 128, 'empty');
		$this->addColumn('CURRENTLYACCESSING', 'DbCurrentlyaccessing', 'INTEGER', true, null, 0);
		$this->addForeignKey('EDITEDBY', 'DbEditedby', 'INTEGER', 'cc_subjs', 'ID', false, null, null);
		$this->addColumn('MTIME', 'DbMtime', 'TIMESTAMP', false, 6, null);
		$this->addColumn('CREATOR', 'DbCreator', 'VARCHAR', false, 32, null);
		$this->addColumn('DESCRIPTION', 'DbDescription', 'VARCHAR', false, 512, null);
		// validators
	} // initialize()

	/**
	 * Build the RelationMap objects for this table relationships
	 */
	public function buildRelations()
	{
    $this->addRelation('CcSubjs', 'CcSubjs', RelationMap::MANY_TO_ONE, array('editedby' => 'id', ), null, null);
    $this->addRelation('CcPlaylistcontents', 'CcPlaylistcontents', RelationMap::ONE_TO_MANY, array('id' => 'playlist_id', ), 'CASCADE', null);
	} // buildRelations()

} // CcPlaylistTableMap
