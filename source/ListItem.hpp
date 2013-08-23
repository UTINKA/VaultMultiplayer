#ifndef LISTITEMGUI_H
#define LISTITEMGUI_H

#include "vaultmp.hpp"
#include "Base.hpp"
#include "GameFactory.hpp"
#include "ReferenceTypes.hpp"

/**
 * \brief Represents a GUI list item
 */

class ListItem : public Base
{
		friend class GameFactory;

	private:
		static constexpr bool DEFAULT_SELECTED = false;

		RakNet::NetworkID list;
		bool selected;

		void initialize();

		ListItem(const ListItem&);
		ListItem& operator=(const ListItem&);

	protected:
		ListItem();
		ListItem(const pDefault* packet);
		ListItem(pPacket&& packet) : ListItem(packet.get()) {};

	public:
		virtual ~ListItem() noexcept;

		void SetItemContainer(RakNet::NetworkID list) { this->list = list; }
		void SetSelected(bool selected) { this->selected = selected; }

		RakNet::NetworkID GetItemContainer() const { return list; }
		bool GetSelected() const { return selected; }

		/**
		 * \brief For network transfer
		 */
		virtual pPacket toPacket() const;
};

GF_TYPE_WRAPPER_FINAL(ListItem, Base, ID_LISTITEM)

template<> struct pTypesMap<pTypes::ID_LISTITEM_NEW> { typedef pGeneratorReferenceExtend<pTypes::ID_LISTITEM_NEW, RakNet::NetworkID, bool> type; };
template<> struct pTypesMap<pTypes::ID_UPDATE_WLSELECTED> { typedef pGeneratorReference<pTypes::ID_UPDATE_WLSELECTED, bool> type; };

#endif
